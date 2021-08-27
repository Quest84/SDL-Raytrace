# Define el nombre del binario.
linkTarget = bin

# Define las librerías que se necesitan.
LIBS = -lSDL2

# Defina las flags.
CFLAGS = -std=c++17

# Define los archivos objetos que se necesitarán.
objects = main.o \
		  CApp.o \
		  $(patsubst %.cpp,%.o,$(wildcard ./build/*.cpp))

# Define the rebuildables.
rebuildables = $(objects) $(linkTarget)

# Regla para ejecutar la construcción.
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

# Regla para crear los .o (object) files.
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

clean:
	rm $(rebuildables)
