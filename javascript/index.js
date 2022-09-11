function setter() {
  this.x = 10;
}
var y = 5;
function tester() {
  this.x = 5;
  this.y = 2;
  let inside = function () {
    console.log(this.y, y);
    console.log(this);
    console.log(this.x, x);
  };
  return inside;
}

setter();
var obj = {
  x: 12,
  y: 13,
};
let callTester = new tester();
console.log(callTester, typeof callTester);
callTester.call(obj);
