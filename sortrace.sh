#Jimmy Tran
# Class (CECS 325-02)
# Prog 4 sortrace
# 10/24/23
#
# I certify that this program is my own original work. I did not copy any part of this program from
# any other source. I further certify that I typed each and every line of code in this program.

echo Generating 1000000 random numbers
sleep 1
./generate 1000000 100000 999999  
sleep 1
echo Starting system sort
sleep 1
{ time sort numbers.dat > systemsort.out; } 2>&1>> sortrace.log     
sleep 1
echo Starting my sort
sleep 1
{ time ./mysort numbers.dat mysort.out; } 2>> sortrace.log    
sleep 1                                          
sort -c mysort.out 2>> sortrace.log  		            
