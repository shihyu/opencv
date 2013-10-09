import os
import sys

def parser(filename):

    print filename.name
    #print dir(filename)

    os.system("ctags-exuberant -x " + str(filename.name) + " | ack -w 'function' | ack -v '\{.*\}' > ~/aa");
    os.system("ack -o 'function\s+\d+\s' ~/aa | ack -o '\d+' | sort -n -k 1 > /tmp/a.txt");
    #raw_input("pause") 
    mylist = []
    filelist = []

    n = open("/tmp/a.txt")

    for i in n:
        #print type(i)
        mylist.append(int(i.strip('\n')))
        #print i

    mylist.sort(reverse = True)
    #print mylist
    n.close()

    if len(mylist) > 0:
        #print mylist
        filename = open(str(filename.name), "r+")

        for l in filename:
            filelist.append(l)

        #print filelist
        #print len(filelist)

        #raw_input("pause") 
        filename.close()

        for i in mylist:
            #print i
            for j in range(i-1, len(filelist)):
                #print filelist[j]
                #print str(filelist[j]).find('{')
                #raw_input("xxxx")
                if str(filelist[j]).find('{') != -1:
                    if str(filelist[j]).find('}') != -1:
                        break
                    #print filelist[j]
                    #raw_input("ddd")
                    #print filename.name
                    if  str(filename.name).find('.cpp') != -1:
                        filelist.insert(j+1, '\t::printf ("This is line %d of file %s (function %s)\\n", __LINE__, __FILE__, __func__);\n')
                        break
                    else:
                        filelist.insert(j+1, '\tprintf ("This is line %d of file %s (function %s)\\n", __LINE__, __FILE__, __func__);\n')
                        break

        #print filename.name
        newfile = open(filename.name, "w+")
        newfile.truncate()


        for i in range(0, len(filelist)):
            if str(filelist[i]).find('#include') != -1:
                filelist.insert(i+1, '#include <stdio.h>\n')
                break


        for l in filelist:
            newfile.write(l)

        newfile.close()







    #filename.seek(0)
    #filename.write("hello\n")
    '''
    for l in filename:    
        l = l.strip()
        n = p.findall(l)[0]
        print n
        raw_input("pause\n") 
    '''

def get_nodes(fileList):

    for i in fileList:
        #print i
        #raw_input("pause") 
        fin = open(i,"r+")
        parser(fin)
        fin.close()


def endWith(s, * endstring):
    array =  map (s.endswith,endstring)
    if  True  in  array:
        return  True
    else :
        return  False

if __name__ == "__main__":
    fileList = []
    rootdir = sys.argv[1]
    for root, subFolders, files in os.walk(rootdir):
        for file in files:
            #if  endWith(file, '.h' , '.cpp' , '.c'):
            if  endWith(file, '.cpp' , '.c'):
                #print file
                fileList.append(os.path.join(root,file))

    #print fileList
    #for i in fileList:
        #print i

    get_nodes(fileList)
