#!/usr/bin/python 
import subprocess
Commande="\" ./serveur; exec bash\""
terminal1 = subprocess.Popen(f"gnome-terminal --tab -- bash -c {Commande}",shell=True)
