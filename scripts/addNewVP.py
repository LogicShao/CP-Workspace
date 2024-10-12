import os

contestType = input("Enter the contest type (cf, atc, ...): ")
contestName = input("Enter the contest name: ")

contestDir = "src/" + contestType + "/" + contestName
usrNameList = ['fanta5y', 'ping', 'johntime']

# Create the directory
if not os.path.exists(contestDir):
    os.mkdir(contestDir)

# Create the files
for usrName in usrNameList:
    usrFilePath = contestDir + "/" + usrName
    if not os.path.exists(usrFilePath):
        os.mkdir(usrFilePath)
    os.system(f"touch {usrFilePath}/.gitkeep")

os.system(f"touch {contestDir}/README.md")
