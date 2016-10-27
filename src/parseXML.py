from lxml import etree
from os import listdir


output = ""
for x in listdir("../sujet1/bdd/openssl/openssl-1.0.2h/headers/"):
	output += "#include \""+ str(x) + "\"\n"
	
output += "int main(){\n"
	



tree = etree.parse("output.xml")
root = tree.getroot()

for fdecl in root:
	output += fdecl.get("id")+"("
	print  fdecl.get("id")
	virgule = 0
	for args in fdecl:
		for arg in args:
			typee = arg.get("text")
			if not "*" in typee:
				print "le ttpe", typee
				res = "0"
			else:
				res = "NULL"
			
			print "\t", typee, res
			if "ANON" in arg.get("id"):
				break
			
			if virgule != 0:
				output += ","
			if not (len(args) == 1 and typee == "void"):			
				output += res
			

			virgule = 1
	output += ");\n"
	
output += "}"


f = open("../sujet1/bdd/openssl/openssl-1.0.2h/test.c", "w")
f.write(output)
f.close()
