/* Login page: Sign-in Button */
window.onload = function() {
	signinButton = document.getElementById('signin-button');

	signinButton.addEventListener('click', function() {
		loginID = document.getElementById('loginID').value;

		if(loginID == 'root') {
			window.location = './home.html'
		}
	});
}
