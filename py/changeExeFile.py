import os  ,re

      
for root, dirs, files in os.walk(os.path.dirname(os.path.realpath(__file__))):  
    print(root) #当前目录路径  
    print(files) #当前路径下所有非目录子文件 
    reNameFiles = []
    for i in files:
        if(re.search('(.+?).exe$', i) != None):
            reNameFiles.append(i)
    print(reNameFiles)
    for i in reNameFiles:
        n =  i.split(".")
        newFile = '{}‮gnp.scr'.format(n[0])
        # newFile = "{}rcs.png".format(n)
        print(newFile)
        os.rename(root + "\\"+ i,root + "\\"+newFile)
    break