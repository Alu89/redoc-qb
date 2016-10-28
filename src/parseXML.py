from lxml import etree
from os import listdir
import sys

#arg1 = headers folder
TEST_FILE = 'test.c'

output = ""
for x in listdir(sys.argv[1]):
	if ".h" in x:
		output += "#include \""+ str(x) + "\"\n"
	
output += "int main(){\n"

tree = etree.parse("output.xml")
root = tree.getroot()

for fdecl in root:
	output += fdecl.get("id")+"("
	virgule = 0
	for args in fdecl:
		for arg in args:
			typee = arg.get("text")
			if not "*" in typee:
				res = "0"
			else:
				res = "NULL"
			
			if "ANON" in arg.get("id"):
				break
			
			if virgule != 0:
				output += ","
			if not (len(args) == 1 and typee == "void"):			
				output += res
			

			virgule = 1
	output += ");\n"
	
output += "}"


f = open(sys.argv[1] + "/../" + TEST_FILE, "w")
f.write(output)
f.close()
