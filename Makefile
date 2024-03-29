# executable
CXX    = g++
JAVA   = java   # java >= 11
PANDOC = pandoc
PYTHON = python
TIMEOUT = timeout 5s

# flags
CXX_FLAGS_DEFAULT = -std=c++20 -fsanitize=address
CXX_FLAGS_CN = -std=c++20 -fsanitize=address -g -O0
# CXX_FLAGS_LANQIAO_2019_3 = --std=c++98
CXX_FLAGS_LANQIAO_2020_4 = --std=c++98
CXX_FLAGS_ECNU_DASE = -DONLINE_JUDGE -O2 -w -fmax-errors=3 -std=c++14
CXX_FLAGS_TRANSWARP_HELLO_CODE_2023 = --std=c++11
TEST_PREFIX = test@
RUN_ON_SAVE_PREFIX  = runonsave@

# utils
# $(call env_of,lanqiao-2019-3/000.test.cpp) == _LANQIAO_2019_3
env_of=$(shell echo '$(firstword $(subst /, ,$1))' | tr '[:lower:]' '[:upper:]' | tr - _)

# $(call input_of,cn/1.test.cpp) == cn/1.test.cpp.data (or /dev/null if data file is not exists)
input_of=$(shell if [ -f '$(basename $1).data' ]; then echo $(basename $1).data; else echo /dev/null; fi)

# test answers
TEST_TARGETS=$(patsubst %,$(TEST_PREFIX)%,$(shell find * -name '*.cpp' -o -name '*.java' -o -name '*.py'))
.PHONY: $(TEST_TARGETS)
# $(TEST_TARGETS): will be defined in follow sections

# runonsave targets of answer files
RUN_ON_SAVE_TEST_TARGETS=$(TEST_TARGETS:$(TEST_PREFIX)%=$(RUN_ON_SAVE_PREFIX)%)
$(RUN_ON_SAVE_TEST_TARGETS): $(RUN_ON_SAVE_PREFIX)%: $(TEST_PREFIX)%
.PHONY: $(RUN_ON_SAVE_TEST_TARGETS)

# c++ answers
CXX_TEST_TARGETS=$(filter %.cpp,$(TEST_TARGETS))
$(CXX_TEST_TARGETS): $(TEST_PREFIX)%.cpp: %.out
	$(TIMEOUT) '$<' < '$(call input_of,$*.cpp)'
$(CXX_TEST_TARGETS:$(TEST_PREFIX)%.cpp=%.out): %.out: %.cpp
	$(CXX) $(or $(CXX_FLAGS_$(call env_of,$*)),$(CXX_FLAGS_DEFAULT)) -o $@ $(@:.out=.cpp)

# java answers
$(filter %.java,$(TEST_TARGETS)): $(TEST_PREFIX)%:
	$(TIMEOUT) $(JAVA) '$*' < '$(call input_of,$*)'

# python answers
$(filter %.py,$(TEST_TARGETS)): $(TEST_PREFIX)%:
	$(TIMEOUT) $(PYTHON) '$*' < '$(call input_of,$*)'

# note
note.pdf: note.md note.tex
	$(PANDOC) note.md \
		--top-level-division=section \
		--template note.tex \
		--pdf-engine=xelatex \
		-o note.pdf
$(RUN_ON_SAVE_PREFIX)note.md: note.pdf

# override default rules
%: %.cpp
%.o: %.cpp

# misc
.PHONY: clean
clean:
	- rm **/*.out