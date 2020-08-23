# utils
env_of=$(shell echo '$(patsubst %/,%,$(dir $1))' | tr '[:lower:]' '[:upper:]' | tr - _)

# flags
# CXX_FLAGS_LANQIAO_2019_3=--std=c++98
CXX_FLAGS_LANQIAO_2020_4=--std=c++98

# targets
PROBLEMS=$(basename $(wildcard **/*.cpp))

.PHONY: $(PROBLEMS)
$(PROBLEMS): %: %.out
	@echo "running $@.out"
	@if [ -f "$@.data" ]; then time timeout 5s ./$@.out < $@.data; else timeout 5s ./$@.out; fi

$(addsuffix .out,$(PROBLEMS)): %.out: %.cpp
	g++ $(CXX_FLAGS_$(call env_of, $*)) -o $@ $(@:.out=.cpp)

%: %.cpp
%.o: %.cpp

.PHONY: clean
clean:
	- rm **/*.out