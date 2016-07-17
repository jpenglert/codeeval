/*
You are given a sorted list of numbers with duplicates. Print out the sorted list with duplicates removed.

INPUT SAMPLE:

File containing a list of sorted integers, comma delimited, one per line. E.g. 

1,1,1,2,2,3,3,4,4
2,3,4,5,5
OUTPUT SAMPLE:

Print out the sorted list with duplicates removed, one per line. 
E.g.

1,2,3,4
2,3,4,5
*/

var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line.trim() != "") {
        var output = ""
        var previousNumber = -1
        line.trim().split(',').forEach(function (num) {
            if (num != previousNumber) {
                output += num + ","
            }
            previousNumber = num
        })

        // Remove trailing comma
        if (output.length > 1) {
            output = output.substr(0, output.length - 1)
        }
        
        console.log(output);
    }
});