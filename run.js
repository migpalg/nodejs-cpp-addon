const { fibo } = require("./index");

function jsfibo(n) {
  if (n <= 1) {
    return n;
  }

  return jsfibo(n - 2) + jsfibo(n - 1);
}

function executeTimes(callback, ...args) {
  let start, end;

  start = Date.now();
  const result = callback(...args);
  end = Date.now();

  return [end - start, result];
}

function main() {
  const target = 40;

  const [nativeResultTime, nativeResult] = executeTimes(fibo, target);
  const [jsResultTime, jsResult] = executeTimes(jsfibo, target);

  console.log(`nativeResultTime: ${nativeResultTime}ms -> ${nativeResult}`);
  console.log(`jsResultTime: ${jsResultTime}ms -> ${jsResult}`);
}

main();
