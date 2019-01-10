var deleteMode = false

window.onload = function() {
	var homeCreateButton = document.getElementById('home-create-button');
	var homeDeleteButton = document.getElementById('home-delete-button');
	var memeDialog = document.getElementById('memeDialog');
	var memesContent = document.getElementById('memesList');

	homeCreateButton.addEventListener('click', function() {
			memeDialog.showModal();
	});

	homeDeleteButton.addEventListener('click', function() {
		deleteMode = !deleteMode;
		navbar = document.getElementsByClassName('navbar')[0];

		if(deleteMode) {
			navbar.style.backgroundColor='red';
		} else {
			homeDeleteButton.style.color="white";
			navbar.style.backgroundColor='black';
		}	
	});

	/* Add memes to the list*/
	var createCancelButton = document.getElementById('create-cancel-button');
	var createCreateButton = document.getElementById('create-create-button');

	createCancelButton.addEventListener('click', function() {
			memeDialog.close();
	});

	createCreateButton.addEventListener('click', function() {
		filename = document.getElementById('fileName').value;

			memePrevArea = document.getElementById('memePreviewArea');
			html2canvas(memePrevArea).then(function(canvas) {
					var img = new Image();
					img.src = canvas.toDataURL();
					img.alt=filename;
					img.onclick = function() {
						deleteMeme(this);
					};

					memesContent.append(img);
					memeDialog.close();
			});
	});
}

function deleteMeme(meme) {
	if(deleteMode) {
		memes = document.getElementById('memesList');
		console.log(meme);
		memes.removeChild(meme);
	}
}


/* Previewing image for the selected file */
function readURL(input) {

	if (input.files && input.files[0]) {
		var reader = new FileReader();

		reader.onload = function(e) {
			$('#meme-image').attr('src', e.target.result);
		}
		reader.readAsDataURL(input.files[0]);
	}
}

/* Live update texts */
function updateTopText() {
	document.getElementById('memeTopText').innerHTML = document.getElementById('topText').value;
}

function updateBottomText() {
	document.getElementById('memeBottomText').innerHTML = document.getElementById('bottomText').value;
}

function updateTopFontSize() {
	toptext = document.getElementById('memeTopText');
	topFontSize = document.getElementById('topFontSize');
	toptext.style.fontSize = topFontSize.value + 'px';
}

function updateBottomFontSize() {
	bottomtext = document.getElementById('memeBottomText');
	bottomFontSize = document.getElementById('bottomFontSize');
	bottomtext.style.fontSize = bottomFontSize.value + 'px';
}
