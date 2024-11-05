import os

contestTypeList = ['cf', 'atc', 'xcpc']

contestType = input("Enter the contest type ({}): ".format(
    ", ".join(contestTypeList)))
contestName = input("Enter the contest name: ")

assert contestType in contestTypeList, "Invalid contest type"

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
    open(f"{usrFilePath}/.gitkeep", 'a').close()
