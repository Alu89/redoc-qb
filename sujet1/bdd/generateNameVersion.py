import os

for f in os.listdir("./"):
	if f in ["openssl", "zlib"]:
		for ff in os.listdir("./" + f):
			print f, ff
			fff = open("./" + f + "/" + ff + "/" + "name.txt", "w")
			fff.write(f)
			fff.close()
			
			fff = open("./" + f + "/" + ff + "/" + "version.txt", "w")
			fff.write(ff.split("-")[1])
			fff.close()
