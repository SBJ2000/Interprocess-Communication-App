# Interprocess-Communication-App

![Project Logo](https://github.com/SBJ2000/Interprocess-Communication-App/blob/main/Images/Logo.jpg)

## Project Description

Interprocess Communication App: This repository contains a client-server application for communication between processes using named pipes and TCP/IP sockets. The client generates a random number and sends it to the server, which responds with a that number of random numbers. The project includes backend code in C and a frontend interface in Python, providing a user-friendly graphical interface for easy interaction. Explore the code and learn about interprocess communication techniques and random number generation.

### Project Architecture :

Before going into the application, we need to understand correctly the architecture that the developer adapted to build his project & what are the tools needed, which is in this case:

First we have the Back end named pipe architecture : 

![Named Pipe Architecture](https://github.com/SBJ2000/Interprocess-Communication-App/blob/main/Images/NamedPipeArchitecture.jpg)

Then we will discover the Socket Backend architecture:

![Socket Architecture](https://github.com/SBJ2000/Interprocess-Communication-App/blob/main/Images/SocketArchitecture.jpg)

The user will manipulate the application using a graphical interface written in python code distributed as follows:

![Front End Architecture](https://github.com/SBJ2000/Interprocess-Communication-App/blob/main/Images/FrontEndArchitecture.png)

## Installation & Usage

### Prerequisites

[![GCC Compiler](https://img.shields.io/badge/GCC%20Compiler-9.3.0-blue)](https://gcc.gnu.org/)

    C Compiler: You need a C compiler to compile the backend code. One popular option is the GNU Compiler Collection (GCC).

[![Python](https://img.shields.io/badge/Python-3.9.2-blue)](https://www.python.org/)

    Python: The frontend interface is written in Python, so you need to have Python installed on your system.

[![PythonPackages](https://img.shields.io/badge/Python_Packages-2.0-blue)](https://pypi.org/project/requests/)

    Python Packages: The Python code relies on several packages, which can be installed using the pip package manager

[![GitHub](https://img.shields.io/badge/GitHub-Repo-blue?logo=github)](https://github.com/john-doe/my-project)

    Git: Git is a version control system used to clone the project repository and manage the code.

![Visual Studio Code](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-blue)

    IDE or Text Editor: You can use any IDE or text editor of your choice to view and modify the code. Some popular options for C and Python development include Visual Studio Code, PyCharm, and Sublime Text.

[![Ubuntu](https://img.shields.io/badge/Ubuntu-20.04%20LTS-orange)](https://ubuntu.com/)
    Ubuntu Operating System: Ubuntu is a popular Linux-based operating system known for its user-friendly interface and stability and you can use Version: Ubuntu 20.04 LTS

### Installation

To install and set up the Interprocess-Communication-App project, follow these steps:

1- Clone this Repository using this commande:

    git clone https://github.com/SBJ2000/Interprocess-Communication-App.git
Then navigate to the project  :
    
    cd Interprocess-Communication-App

2- Set up the Backend:
    You need just to run the make file to compile the backend's files, using this commande:

    Make

3- Install the Python Dependencies:
    
    pip install tk

4- Start the Frontend:

    python Main_Gui_Python.py

### Usage

After installing it, you can now enjoy running and using the application throw this interafce:

![Front End](https://github.com/SBJ2000/Interprocess-Communication-App/blob/main/Images/FrontEnd.png)

## Additional Information

For additionnal information especially for the code you can read the report in the report folder.

## Conclusion

The Interprocess-Communication-App is a client-server application that enables communication between processes using named pipes and TCP/IP sockets. It consists of a C backend and a Python frontend. The backend handles random number generation and exchange, while the frontend provides a user-friendly graphical interface.

The application allows you to generate and exchange random numbers through an intuitive interface. It's a practical project showcasing interprocess communication and random number generation.

In summary, the Interprocess-Communication-App facilitates interprocess communication using named pipes and sockets, with a C backend and Python frontend. Install the prerequisites, set up the project, and enjoy the user-friendly interface for random number exchange.