LIBRARIES = -lglfw -lrt -lm -ldl -lXrandr -lXinerama -lXi -lXcursor -lXrender -lGL -lm -lpthread -ldl -ldrm \
						-lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp

DEPENDENCIES = dependencies/glad/glad.c dependencies/stb/stb_image.cpp

GRAPHICS = src/graphics/window.cpp src/shader.cpp src/mesh.cpp

all: bin/place #bin/holy_c

#bin/holy_c: holy_c.cpp
#	g++ $(DEPENDENCIES) $^ -o $@ $(LIBRARIES)

#ohrly: gl_triang.cpp
bin/place: src/main.cpp $(GRAPHICS)
	g++ $(DEPENDENCIES) $^ -o $@ $(LIBRARIES)

.PHONY: clean
clean:
	rm -rf bin/place

#pkg-config --static --libs glfw3
