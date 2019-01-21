
const char PAGE_Style_css[] PROGMEM = R"=====(
body { color: #000000; font-family: avenir, helvetica, arial, sans-serif;  letter-spacing: 0.15em;} 
hr {    background-color: #eee;    border: 0 none;   color: #eee;    height: 1px; } 
.btn, .btn:link, .btn:visited {  
	border-radius: 0.3em;  
	border-style: solid;  
	border-width: 1px;  
color: #111;  
display: inline-block;  
	font-family: avenir, helvetica, arial, sans-serif;  
	letter-spacing: 0.15em;  
	margin-bottom: 0.5em;  
padding: 1em 0.75em;  
	text-decoration: none;  
	text-transform: uppercase;  
	-webkit-transition: color 0.4s, background-color 0.4s, border 0.4s;  
transition: color 0.4s, background-color 0.4s, border 0.4s; 
} 
.btn:hover, .btn:focus {
color: #7FDBFF;  
border: 1px solid #7FDBFF;  
	-webkit-transition: background-color 0.3s, color 0.3s, border 0.3s;  
transition: background-color 0.3s, color 0.3s, border 0.3s; 
}
	.btn:active {  
color: #0074D9;  
border: 1px solid #0074D9;  
		-webkit-transition: background-color 0.3s, color 0.3s, border 0.3s;  
transition: background-color 0.3s, color 0.3s, border 0.3s; 
	} 
	.btn--s 
	{  
		font-size: 12px; 
	}
	.btn--m { 
		font-size: 14px; 
	}
	.btn--l {  
		font-size: 20px;  border-radius: 0.25em !important; 
	} 
	.btn--full, .btn--full:link {
		border-radius: 0.25em; 
display: block;  
			margin-left: auto; 
			margin-right: auto; 
			text-align: center; 
width: 70%; 
	} 
  .btn--blue:link, .btn--blue:visited {
color: #fff;  
    background-color: #0074D9; 
  }
  .btn--blue:hover, .btn--blue:focus {
color: #fff !important;  
    background-color: #0063aa;  
    border-color: #0063aa; 
  }
  .btn--blue:active {
color: #fff; 
    background-color: #001F3F;  border-color: #001F3F; 
  }
  .btn--red:link, .btn--red:visited {
color: #fff;  
    background-color: #5574D9; 
  }
  .btn--red:hover, .btn--red:focus {
color: #fff !important;  
    background-color: #5563aa;  
    border-color: #5563aa; 
  }
  .btn--red:active {
color: #fff; 
    background-color: #551F3F;  border-color: #551F3F; 
  }
  .btn--yelo:link, .btn--yelo:visited {
color: #fff;  
    background-color: #f4f142; 
  }
  .btn--yelo:hover, .btn--yelo:focus {
color: #fff !important;  
    background-color: #7a7821;  
    border-color: #7a7821; 
  }
  .btn--yelo:active {
color: #fff; 
    background-color: #c1bf3c;  border-color: #c1bf3c; 
  }
  .btn--black:link, .btn--black:visited {
color: #fff;  
    background-color: #000000; 
  }
  .btn--black:hover, .btn--black:focus {
color: #fff !important;  
    background-color: #000000;  
    border-color: #7a7821; 
  }
  .btn--black:active {
color: #fff; 
    background-color: #000000;  border-color: #c1bf3c; 
  }
	@media screen and (min-width: 28em) {
		.btn--full {  
			max-width: 14em !important; } 
	}
)=====";
 
