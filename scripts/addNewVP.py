import os

contestName = input("Enter the contest name: ")

srcdir = "src/" + contestName
usrNameList = ['fanta5y', 'ping', 'johntime']

# Create the directory
os.mkdir(srcdir)

# Create the files
for usrName in usrNameList:
    os.system(f"touch {srcdir}/{usrName}/.gitkeep")
