PROBLEMS=$(basename $(wildcard **/*.cpp))

$(PROBLEMS): %: %.out
	./$@.out

$(addsuffix .out,$(PROBLEMS)): %.out: %.cpp
	g++ -o $@ $(@:.out=.cpp)

.PHONY: clean $(PROBLEMS)
clean:
	- rm *.out