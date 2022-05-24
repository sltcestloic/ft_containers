CXX=clang++
CXXFLAGS=-Wall -Werror -std=c++11

all: $(patsubst %.cpp, %.out, $(wildcard */*/*.cpp))

%.out: %.cpp Makefile
	@mkdir -p output/vector
	@$(CXX) $(CXXFLAGS) $< -o $(@:.out=)
	@./$(@:.out=)
	@$(CXX) $(CXXFLAGS) $< -o $(@:.out=) -D USING_STD=true
	@./$(@:.out=)

clean: $(patsubst %.cpp, %.clean, $(wildcard */*/*.cpp))

%.clean:
	@rm -f $(@:.clean=)