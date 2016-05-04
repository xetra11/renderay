OBJ = renderay_core.o renderay_shapes.o

librenderay: $(OBJ)
	ar rcs ../dist/librenderay.a $(OBJ)

%.o : %.c
	gcc -c $<
