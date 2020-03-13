PROBLEMS=$(basename $(wildcard **/*.cpp))

$(PROBLEMS): %: %.out
	timeout 5s ./$@.out

$(addsuffix .out,$(PROBLEMS)): %.out: %.cpp
	g++ -o $@ $(@:.out=.cpp)

%: %.cpp
%.o: %.cpp

.PHONY: clean $(PROBLEMS)
clean:
	- rm *.out