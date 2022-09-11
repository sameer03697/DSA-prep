function test() {
    this.t = 1;

    function f2() {
        console.log('this.t', this.t);
    }

    f2();

    return function() {
        console.log('this.t2', this.t);
    }
}

// test()();

this.x = 5;
function f3() {
    console.log(this.x);
}
f3();