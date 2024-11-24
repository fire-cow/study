obj_file += main.o


gccflags 	+= -std=c99
gcc_flags	+= -I .

ldflags     += -Wl,-Map=main.map

GCC			= gcc

main: $(obj_file)
	$(GCC) $(gcc_flags) $(ldflags) $^ -o a

$(obj_file): %.o: %.c
	$(GCC) $(gcc_flags) -c $< -o $@


clean:
	del -rf $(obj_file) *.map a.exe a *.o 	#cmd
	#rm -rf $(obj_file) *.map a.exe a *.o

.PHONY: clean


