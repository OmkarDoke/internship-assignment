function printAllChild(id) {
    let child=Tree.filter((node) => node.parent == id);
    child.forEach(node=>{
        child.push(...printAllChild(node.id))
    })
    
    return child;
}

Tree = [
    { id: 0, value: "Zero", parent: -1 },
    { id: 1, value: "One", parent: 0 },
    { id: 2, value: "Two", parent: 1 },
    { id: 3, value: "Three", parent: 1 },
    { id: 4, value: "Four", parent: 1 },
    { id: 5, value: "Five", parent: 1 },
    { id: 6, value: "Six", parent: 4 },
    { id: 7, value: "Seven", parent: 4 },
    { id: 8, value: "Eight", parent: 5 },
    { id: 9, value: "Nine", parent: 5 },
    { id: 10, value: "Ten", parent: 7 },
    { id: 11, value: "Eleven", parent: 7 },
    { id: 12, value: "Twelve", parent: 5 },
    { id: 13, value: "Thirteen", parent: 6 },
    { id: 14, value: "Fourteen", parent: 9 },
];

Tree.forEach((element) => {
    let { id, value, parent } = element
    let result = printAllChild(id)
    if (result.length) {
        console.log(`Child of id=${id} value=${value} parentid=${parent}`);
        console.table(result);
    }
});
