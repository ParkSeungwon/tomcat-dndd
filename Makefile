all : 
	make -C src/
	make -C obj/

PHONY : clean

clean :
	rm obj/*.o obj/*.x *.cgi

ls :
	echo $(EXE)
