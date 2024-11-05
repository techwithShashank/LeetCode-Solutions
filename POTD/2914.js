function beautycnt(string) {
  let beauty = 0;
  for (let i = 0; i < s.lenght - 1; i += 2) {
    if (s[i] != s[i + 1]) {
      beauty += 1;
    }
  }
  return beauty;
}
let string = prompt("Enter The String");
if (string.size % 2 != 0) console.log("Invalid ODD String");
else console.log(beautycnt(string));
