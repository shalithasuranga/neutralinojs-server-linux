echo "Neutralino is being built.."
if [ -e bin/neutranino.out ]; then 
    rm bin/neutralino.out
fi

gcc src/httpserver.c -pthread -o bin/neutralino -w