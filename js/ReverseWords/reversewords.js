/*
Write a program which reverses the words in an input sentence.

INPUT SAMPLE:

The first argument is a file that contains multiple sentences, one per line. Empty lines are also possible.

For example:

Hello World
Hello CodeEval
OUTPUT SAMPLE:

Print to stdout each sentence with the reversed words in it, one per line. Empty lines in the input should be ignored. Ensure that there are no trailing empty spaces in each line you print.

For example:

World Hello
CodeEval Hello
*/

var fs  = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    line = line.trim()
    if (line != "") {
        var strArr = line.split(' ')
        var newStr = ""
        for (var i = strArr.length - 1; i >= 0; --i) {
            newStr += strArr[i] + " "
        }
        
        console.log(newStr.trim());
    }
});