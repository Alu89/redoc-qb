#!/bin/bash
# date : 25/10/2016
# author: mab 
# MatchLibVersion.sh link a dynamic library to an executable in order to check if there is a linking error  
#
#Usage
#./MatchLibVersion.sh path_to_candidate_lib library_type executable 
#
#
#Example 
#./MatchLibVersion.sh  ~/redoc-qb/sujet1/bdd/openssl_1.1.0b/libssl.so.1.1 libssl ./ssl_test


#Check the number of arguments 
if [[ $# -ne 3 ]]; then
 	echo "Usage: ./MatchLibVersion.sh path_to_condidate_lib library_type executable  "
 	exit
 fi

path_to_condidate_library=$1
library_type=$2
path_to_executable=$3

#Finds the version of library linked to the executable
libs=$(ldd ${path_to_executable}  |  egrep -o "${library_type}\.so\.([0-9]{1,}\.)*[0-9]+") 
# convert the array to column array 
libs=($libs)

#Check if the executable link with the library 
if [ "${#libs[@]}" -lt  1 ]; then
	echo "${library_type} not found in ${path_to_executable}"
	ldd ${path_to_executable}       
    exit 
fi

#Make a copy the library with the right name in the current directory 
$(cp ${path_to_condidate_library} ${libs[0]})

# print ldd to check in the local lib is loaded 
LD_LIBRARY_PATH=. ldd ${path_to_executable}

#Rename the library to match to the found version
$(LD_LIBRARY_PATH=. ${path_to_executable})

#Delete the local copy of the lib 
$(rm ${libs[0]})
