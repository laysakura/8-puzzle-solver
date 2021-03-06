# http://osima.jp/blog/makefile-and-wildcard.html
SRCS = $(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DEPENDS=$(patsubst %.cpp,%.d,$(SRCS))
TARGET = 8-puzzle
TARGETS = $(TARGET)

include Makefile.in			#TARGETSとかの後じゃないとだめ

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

# こいつのおかげで、ヘッダファイルの依存性を勝手に(しかもインテリジェントに)解決してくれる
# http://d.hatena.ne.jp/ritchey/20070519/1179595462
%.d: %.cpp
	@set -e; $(CXX) -MM $(CXXFLAGS) $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@
-include $(DEPENDS)
