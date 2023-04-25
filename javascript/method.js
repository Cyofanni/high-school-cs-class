var meth = function() {
    console.log(this.name);
}

var obj = {'name': 'mario', 'surname': 'rossi', 'printName': meth};
obj.printName();
