#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp
import re

def testCode( retcode, msg ):
    if retcode > 0:
        print msg
        sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'moreTestcases')
if not os.path.isdir( testDir ):
    print testDir, "isn't a directory"
    sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if not os.path.isfile( executable ):
    retcode = subprocess.call("make",shell=True)
    testCode( retcode, "\tFAILED to make the scanner" )
else:
    retcode = subprocess.call("make clean",shell=True)
    testCode( retcode, "\tFAILED to make clean the scanner" )
    retcode = subprocess.call("make",shell=True)
    testCode( retcode, "\tFAILED to make the scanner" )


def generateAndSortMccabeResult(testFile, outFile):
    retcode = subprocess.call("python -m mccabe " + testFile + " > " + outFile, shell=True)
    testCode( retcode, "\tFAILED to make the out by mccabe" )
    with open(outFile, 'r') as f:
      lines = f.readlines()
    f.close()
    toBeSorted = {}
    for line in lines:
        if ':' in line:
            lineNum = int(re.findall("\(\"(.*?):", line, re.DOTALL)[0])
        else:
            lineNum = int(re.findall(" (.*?)\',", line, re.DOTALL)[0])
        toBeSorted[lineNum] = line

    with open(outFile, 'w') as f:
      for key in sorted(toBeSorted):
        f.write(toBeSorted[key])
    f.close()



files = os.listdir( testDir )
for x in files:
    if fnmatch.fnmatch(x, "*.py"):
        testcase = os.path.join(testDir, x)
        output = testcase[:-3]+".out"
        generateAndSortMccabeResult(testcase, output)

        retcode = subprocess.call("./run < "+testcase+"> /tmp/out",shell=True)
        if retcode != 0:
            testCode( retcode, "\tFAILED to run test case "+x)
        else:
            if not os.path.isfile( output ):
                print "test case", x[:-3]+'.out', "doesn't exist"
                sys.exit( 1 )
            if not filecmp.cmp("/tmp/out", output): 
		subprocess.call("diff "+output+" /tmp/out -y",shell=True)
                print "\tTEST CASE FAILED", x
            else :
                print "testcase:", x, "passed"

