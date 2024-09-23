import os

contestName = input("Enter the contest name: ")

contestDir = "src/" + contestName
usrNameList = ['fanta5y', 'ping', 'johntime']

# Create the directory
if not os.path.exists(contestDir):
    os.mkdir(contestDir)

# Create the files
for usrName in usrNameList:
    if not os.path.exists(f"{contestDir}/{usrName}"):
        os.makedirs(f"{contestDir}/{usrName}")
    os.system(f"touch {contestDir}/{usrName}/.gitkeep")

os.system(f"touch {contestDir}/Tutorial.md")
