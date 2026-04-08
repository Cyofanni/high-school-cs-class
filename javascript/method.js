let meth = function() {
    console.log(this.name);
}

let obj = {'name': 'mario', 'surname': 'rossi', 'printName': meth};
obj.printName();
