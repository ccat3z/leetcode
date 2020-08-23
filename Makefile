# utils
env_of=$(shell echo '$(patsubst %/,%,$(dir $1))' | tr '[:lower:]' '[:upper:]' | tr - _)

# flags
CXX    = g++
# CXX_FLAGS_LANQIAO_2019_3 = --std=c++98
CXX_FLAGS_LANQIAO_2020_4 = --std=c++98
PANDOC = pandoc
TEST_PREFIX = test@
RUN_ON_SAVE_PREFIX  = runonsave@

# cpp answers
CXX_TEST_TARGETS=$(patsubst %,$(TEST_PREFIX)%,$(wildcard **/*.cpp))
.PHONY: $(CXX_TEST_TARGETS)
$(CXX_TEST_TARGETS): $(TEST_PREFIX)%.cpp: %.out
	@echo "running $<"
	@if [ -f "$*.data" ]; then timeout 5s $< < $*.data; else timeout 5s $<; fi
$(CXX_TEST_TARGETS:$(TEST_PREFIX)%.cpp=%.out): %.out: %.cpp
	$(CXX) $(CXX_FLAGS_$(call env_of,$*)) -o $@ $(@:.out=.cpp)
$(CXX_TEST_TARGETS:$(TEST_PREFIX)%=$(RUN_ON_SAVE_PREFIX)%): $(RUN_ON_SAVE_PREFIX)%: $(TEST_PREFIX)%

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