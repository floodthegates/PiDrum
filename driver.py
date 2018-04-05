from Tkinter import *
from tkFileDialog   import askopenfilename

def newKit():
    print "New File!"
def openKit():
    name = askopenfilename()
    print name
def about():
    print "About accessed"
def newKit():
    print "newKit accessed"
def openKit():
    print "openKit accessed"
def deleteKit():
    print "deleteKit accessed"
def uploadSound():
    print "uploadSound accessed"
def deleteSound():
    print "deleteSound accessed"

root = Tk()
menu = Menu(root)
root.config(menu=menu)
filemenu = Menu(menu)
menu.add_cascade(label="File", menu=filemenu)
filemenu.add_command(label="Create New Kit", command=newKit())
filemenu.add_command(label="Open Existing Kit", command=openKit())
filemenu.add_command(label="Delete a Kit", command=deleteKit())
filemenu.add_separator()
filemenu.add_command(label="Exit", command=root.quit)

soundMenu = Menu(menu)
menu.add_cascade(label="Sound", menu=soundMenu)
soundMenu.add_command(label="Upload Sound", command=uploadSound())
soundMenu.add_command(label="Delete Sound", command=deleteSound())

helpmenu = Menu(menu)
menu.add_cascade(label="Help", menu=helpmenu)
helpmenu.add_command(label="About...", command=about)



mainloop()
