g++ -o engine ./src/main.cpp ./src/system/window_manager.cpp ./src/system/systemfile_manager.cpp ./src/shaders/shader.cpp ./src/components/component.cpp ./src/components/mesh.cpp ./src/object.cpp ./src/script_manager.cpp -L .\lib\ -lglew32 -lglfw3 -lopengl32 -lgdi32