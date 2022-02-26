
function convertInto(input) {
    let result = "";
    if (input.includes("=>")) {
        let [fname , parameters]=input.split("=")
        fname=fname.split(" ")[1]
        let body=input.split("=>")[1]
        result += `function ${fname}${parameters} { \n ${body} \n}`
    } else {
        let nameStart=input.indexOf(" ");
        let firstPara = input.indexOf("(");
        let lastPara = input.indexOf(")");
        let functionName=input.slice(nameStart,firstPara);
        let parameters = input.slice(firstPara, lastPara + 1)
        let body = input.slice(lastPara + 1)
        result = `let ${functionName} = ${parameters} =>${body} `
    }
    console.log(result)

}

input=""
input=`let pow=(x,y) => console.log(x**y)`
convertInto(input)
input = `function inp(x,y)
{
    for(let i=x;i<=y;i++) 
    console.log(x)
}`
convertInto(input)