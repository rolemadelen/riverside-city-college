let size = parseInt(prompt("grid size: "));
let cells;
let reset;
let count = 0;

console.log(size);

function createTemplate() {
    const div_main = document.createElement('div');
    div_main.classList.add('etch-a-sketch');

    const div_header = document.createElement('div');
    div_header.classList.add('header');

    const h1 = document.createElement('h1');
    h1.textContent = 'Etch A Sketch';

    div_header.appendChild(h1);
    div_main.appendChild(div_header);

    document.body.appendChild(div_main);
}

function createBoard() {
    if(size <= 0 || isNaN(size)) {
        console.log('Minimum grid size is 1');
        size = 1;
    } else if(size > 64) {
        console.log('Maximum grid size is 64.');
        size = 64;
    }

    const boardDiv = document.createElement('div');
    boardDiv.classList.add('board-container');

    for (var index = 0; index < size; ++index) {
        let row = document.createElement('div');
        row.classList.add('row');
        for (var jndex = 0; jndex < size; ++jndex) {
            let col = document.createElement('div');
            col.classList.add('col');
            row.appendChild(col);
        }
        boardDiv.appendChild(row);
    }
    document.querySelector('.etch-a-sketch').appendChild(boardDiv);
}

function createResetButton() {
    const div = document.createElement('div');
    div.classList.add('reset');
    document.querySelector('.etch-a-sketch').appendChild(div);
    
}

createTemplate();
createBoard();
createResetButton();

cells = document.querySelectorAll('.col');

cells.forEach(cell => {
    cell.addEventListener('mouseenter', (e) => {
        let R, G, B;

        if(count == 10) {
            R = G = B = 0;
            count = 0;
        } else {
            ++count;
            R = Math.floor(Math.random() * 255 + 1);
            G = Math.floor(Math.random() * 255 + 1);
            B = Math.floor(Math.random() * 255 + 1);
        }

        cell.style.backgroundColor = `rgba(${R}, ${G}, ${B}, 1.0)`;
    });
});

reset = document.querySelector('button');
reset.addEventListener('click', (e) => {
    location.reload();
});