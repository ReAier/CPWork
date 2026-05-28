import subprocess
import sys

inter = subprocess.Popen(['inter.exe'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
sol = subprocess.Popen(['qoj5309.exe'], stdin=inter.stdout, stdout=inter.stdin)

sol.wait()
inter.wait()
