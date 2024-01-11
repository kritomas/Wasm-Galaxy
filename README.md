# Wasm Galaxy

Wasm Galaxy is an online repo of web assembly games, made as a homework assignment for school.

# Games

We got:
+	Hex Color Guessing Game
+	Tic Tac Toe

# How to run

Due to security constraints surrounding WebAssembly, the games cannot be run directly. A HTTP server has to be used:

1.	Run `python3 -m http.server` in this repo's root directory (Or run `deploy.sh`, which does this for you).
2.	With a web browser, go to the address 127.0.0.1:8000s