
function getFinalProduct(...args) {
    let sum = 0;
    for (let arg of args)
        sum += arg;
        console.log("Arg Sum:",sum);
        if (sum<0)
        sum*=-1
    while (sum > 9) {
        
        let digitProduct = 1;
        let temp = sum.toString()
        for (digit of temp) {
            digitProduct *= digit;
            sum = parseInt(digitProduct)
        }
        console.log("Digit's product:",sum);

    }
    console.log("Final single digit product:",sum);

}

getFinalProduct(1, 2,-100, 3)
getFinalProduct(1, 5, 6, 8,-44, 9,234,12)
