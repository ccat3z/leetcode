# utils
env_of=$(shell echo '$(patsubst %/,%,$(dir $1))' | tr '[:lower:]' '[:upper:]' | tr - _)

# flags
CXX    = g++
# CXX_FLAGS_LANQIAO_2019_3 = --std=c++98
CXX_FLAGS_LANQIAO_2020_4 = --std=c++98
PANDOC = pandoc
TEST_PREFIX = test@

# answers
ANSWER_FILES=$(wildcard **/*.cpp)
TEST_TARGETS=$(ANSWER_FILES:%=$(TEST_PREFIX)%)
.PHONY: $(TEST_TARGETS)

## *.cpp answers
CXX_TEST_TARGETS=$(filter %.cpp,$(TEST_TARGETS))
$(CXX_TEST_TARGETS): $(TEST_PREFIX)%.cpp: %.out
	@echo "running $<"
	@if [ -f "$*.data" ]; then timeout 5s $< < $*.data; else timeout 5s $<; fi
$(CXX_TEST_TARGETS:$(TEST_PREFIX)%.cpp=%.out): %.out: %.cpp
	$(CXX) $(CXX_FLAGS_$(call env_of,$*)) -o $@ $(@:.out=.cpp)

# note
note.pdf: note.md template.tex
	$(PANDOC) note.md \
		--top-level-division=section \
		--template template.tex \
		--pdf-engine=xelatex \
		-o note.pdf

# override default rules
%: %.cpp
%.o: %.cpp

# misc
.PHONY: clean
clean:
	- rm **/*.out