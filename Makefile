PROBLEMS=$(basename $(wildcard **/*.cpp))

$(PROBLEMS): %: %.out
	@echo "running $@.out"
	@if [ -f "$@.data" ]; then timeout 5s ./$@.out < $@.data; else timeout 5s ./$@.out; fi

$(addsuffix .out,$(PROBLEMS)): %.out: %.cpp
	g++ -o $@ $(@:.out=.cpp)

%: %.cpp
%.o: %.cpp

.PHONY: clean $(PROBLEMS)
clean:
	- rm *.out