# MemeMaster

UCSD CSE 134B - HW6

Github: [link](https://github.com/jmyoi/MemeMaster) <br />
Firebase: [Demo](https://mememaster-5bb4a.firebaseapp.com/pages/login.html)

# Not Working
 - no database
 - no authentication
 - downloading meme
 - editing meme
 - URL import
 
# Login page
- username: `root`
- no-password. Just sign-in after typing 'root' as username.

# Home Page
- Hover over images to share on:
  * facebook
  * Twitter
  * LINE

### Navigation bar
- Create Meme
  * opens a dialog to create new meme.
  * I had separete page `create.html` and `create.js` for this page but due to technical issues, I moved it to a dialog.
  * press cancel - close modal
  * press create - it creates new meme and display it on `home`.
- Delete Meme
  * Click `Delete Meme` to turn on the delete mode. Once its on, the navigation bar turns `red`. A user can then click on memes to delete.
  * Click again to turn off the delete mode.
- Sign Out
  * Goes back to `login.html'
