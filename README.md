# Butterfly

Butterfly is a small video game developed in C++ with OpenGL libraries. This video game was created in the assignment of Computer Graphics of the [Mathematical Sciences](https://matematicas.unmsm.edu.pe/) college in the [UNMSM](https://unmsm.edu.pe/).

## Developers
___ 

- [Mitchell Mirano](https://github.com/Mitchell-Mirano)
- [Sebastián Vásquez](https://github.com/soySebasVR)
- [Merly Balboa](https://github.com/MerlyBalboa)

## Install 
___ 

### **Previous requirements**
___

Install C++ compiler and OpenGL libraries

#### **Ubuntu based distributions**

 ```bash
 sudo apt install build-essential freeglut3 freeglut3-dev libglew-dev mesa-utils
 ```
#### **Arch based distributions**

 ```bash
 sudo pacman -S base-devel freeglut3
 ```
### **Install the video game**
___

- clone the respsitory
```
    git clone https://github.com/Mitchell-Mirano/Butterfly.git 
```
- Change the directory

```
    cd Butterfly
```
- Execute the video game
```
g++ main.cpp -lGL -lGLU -lglut -o ./main && ./main

```



