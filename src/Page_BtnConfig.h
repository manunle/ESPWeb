//
//  HTML PAGE
//

const char PAGE_ButtonConfiguration[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Button Settings</strong>
<hr>
<form action="" method="post">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr>
  <td align="right">Button Topic</td>
  <td><input type="text" id="BtnTopic" name="BtnTopic" value=""></td>
</tr>
<tr>
  <td align="right">Button 1 Label</td>
  <td><input type="text" id="BtnLabel0" name="BtnLabel0" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 1 On Msg</td>
  <td><input type="text" id="BtnOnMsg0" name="BtnOnMsg0" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 1 Off Msg</td>
  <td><input type="text" id="BtnOffMsg0" name="BtnOffMsg0" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 2 Label</td>
  <td><input type="text" id="BtnLabel1" name="BtnLabel1" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 2 On Msg</td>
  <td><input type="text" id="BtnOnMsg1" name="BtnOnMsg1" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 2 Off Msg</td>
  <td><input type="text" id="BtnOffMsg1" name="BtnOffMsg1" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 3 Label</td>
  <td><input type="text" id="BtnLabel2" name="BtnLabel2" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 3 On Msg</td>
  <td><input type="text" id="BtnOnMsg2" name="BtnOnMsg2" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 3 Off Msg</td>
  <td><input type="text" id="BtnOffMsg2" name="BtnOffMsg2" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 4 Label</td>
  <td><input type="text" id="BtnLabel3" name="BtnLabel3" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 4 On Msg</td>
  <td><input type="text" id="BtnOnMsg3" name="BtnOnMsg3" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 4 Off Msg</td>
  <td><input type="text" id="BtnOffMsg3" name="BtnOffMsg3" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 5 Label</td>
  <td><input type="text" id="BtnLabel4" name="BtnLabel4" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 5 On Msg</td>
  <td><input type="text" id="BtnOnMsg4" name="BtnOnMsg4" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 5 Off Msg</td>
  <td><input type="text" id="BtnOffMsg4" name="BtnOffMsg4" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 6 Label</td>
  <td><input type="text" id="BtnLabel5" name="BtnLabel5" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 6 On Msg</td>
  <td><input type="text" id="BtnOnMsg5" name="BtnOnMsg5" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 6 Off Msg</td>
  <td><input type="text" id="BtnOffMsg5" name="BtnOffMsg5" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 7 Label</td>
  <td><input type="text" id="BtnLabel6" name="BtnLabel6" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 7 On Msg</td>
  <td><input type="text" id="BtnOnMsg6" name="BtnOnMsg6" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 7 Off Msg</td>
  <td><input type="text" id="BtnOffMsg6" name="BtnOffMsg6" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 8 Label</td>
  <td><input type="text" id="BtnLabel7" name="BtnLabel7" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 8 On Msg</td>
  <td><input type="text" id="BtnOnMsg7" name="BtnOnMsg7" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 8 Off Msg</td>
  <td><input type="text" id="BtnOffMsg7" name="BtnOffMsg7" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 9 Label</td>
  <td><input type="text" id="BtnLabel8" name="BtnLabel8" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 9 On Msg</td>
  <td><input type="text" id="BtnOnMsg8" name="BtnOnMsg8" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 9 Off Msg</td>
  <td><input type="text" id="BtnOffMsg8" name="BtnOffMsg8" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 10 Label</td>
  <td><input type="text" id="BtnLabel9" name="BtnLabel9" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 10 On Msg</td>
  <td><input type="text" id="BtnOnMsg9" name="BtnOnMsg9" value="" maxlength="9"></td>
</tr>
<tr>
  <td align="right">Button 10 Off Msg</td>
  <td><input type="text" id="BtnOffMsg9" name="BtnOffMsg9" value="" maxlength="9"></td>
</tr>
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Save"></td></tr>
</table>
</form>
<script>

 

window.onload = function ()
{
  load("style.css","css", function() 
  {
    load("microajax.js","js", function() 
    {
        setValues("/admin/buttonvalues");
    });
  });
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";


// Functions for this Page
void send_buttoncfg_value_html()
{
  String values ="";
  values += "BtnTopic|" + (String) config.BtnTopic + "|input\n";
  values += "BtnLabel0|" + (String) config.BtnLabel[0] + "|input\n";
  values += "BtnOnMsg0|" + (String) config.BtnOnMsg[0] + "|input\n";
  values += "BtnOffMsg0|" + (String) config.BtnOffMsg[0] + "|input\n";
  values += "BtnLabel1|" + (String) config.BtnLabel[1] + "|input\n";
  values += "BtnOnMsg1|" + (String) config.BtnOnMsg[1] + "|input\n";
  values += "BtnOffMsg1|" + (String) config.BtnOffMsg[1] + "|input\n";
  values += "BtnLabel2|" + (String) config.BtnLabel[2] + "|input\n";
  values += "BtnOnMsg2|" + (String) config.BtnOnMsg[2] + "|input\n";
  values += "BtnOffMsg2|" + (String) config.BtnOffMsg[2] + "|input\n";
  values += "BtnLabel3|" + (String) config.BtnLabel[3] + "|input\n";
  values += "BtnOnMsg3|" + (String) config.BtnOnMsg[3] + "|input\n";
  values += "BtnOffMsg3|" + (String) config.BtnOffMsg[3] + "|input\n";
  values += "BtnLabel4|" + (String) config.BtnLabel[4] + "|input\n";
  values += "BtnOnMsg4|" + (String) config.BtnOnMsg[4] + "|input\n";
  values += "BtnOffMsg4|" + (String) config.BtnOffMsg[4] + "|input\n";
  values += "BtnLabel5|" + (String) config.BtnLabel[5] + "|input\n";
  values += "BtnOnMsg5|" + (String) config.BtnOnMsg[5] + "|input\n";
  values += "BtnOffMsg5|" + (String) config.BtnOffMsg[5] + "|input\n";
  values += "BtnLabel6|" + (String) config.BtnLabel[6] + "|input\n";
  values += "BtnOnMsg6|" + (String) config.BtnOnMsg[6] + "|input\n";
  values += "BtnOffMsg6|" + (String) config.BtnOffMsg[6] + "|input\n";
  values += "BtnLabel7|" + (String) config.BtnLabel[7] + "|input\n";
  values += "BtnOnMsg7|" + (String) config.BtnOnMsg[7] + "|input\n";
  values += "BtnOffMsg7|" + (String) config.BtnOffMsg[7] + "|input\n";
  values += "BtnLabel8|" + (String) config.BtnLabel[8] + "|input\n";
  values += "BtnOnMsg8|" + (String) config.BtnOnMsg[8] + "|input\n";
  values += "BtnOffMsg8|" + (String) config.BtnOffMsg[8] + "|input\n";
  values += "BtnLabel9|" + (String) config.BtnLabel[9] + "|input\n";
  values += "BtnOnMsg9|" + (String) config.BtnOnMsg[9] + "|input\n";
  values += "BtnOffMsg9|" + (String) config.BtnOffMsg[9] + "|input\n";
  server.send ( 200, "text/plain", values);
  Serial.println(__FUNCTION__); 
  Serial.println(values);  
}

void send_btncfg_html()
{
  
  if (server.args() > 0 )  // Save Settings
  { 
    String temp = "";
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i) == "BtnTopic") config.BtnTopic = urldecode(server.arg(i)); 
      if (server.argName(i) == "BtnLabel0") config.BtnLabel[0] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg0") config.BtnOnMsg[0] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg0") config.BtnOffMsg[0] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel1") config.BtnLabel[1] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg1") config.BtnOnMsg[1] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg1") config.BtnOffMsg[1] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel2") config.BtnLabel[2] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg2") config.BtnOnMsg[2] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg2") config.BtnOffMsg[2] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel3") config.BtnLabel[3] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg3") config.BtnOnMsg[3] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg3") config.BtnOffMsg[3] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel4") config.BtnLabel[4] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg4") config.BtnOnMsg[4] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg4") config.BtnOffMsg[4] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel5") config.BtnLabel[5] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg5") config.BtnOnMsg[5] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg5") config.BtnOffMsg[5] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel6") config.BtnLabel[6] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg6") config.BtnOnMsg[6] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg6") config.BtnOffMsg[6] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel7") config.BtnLabel[7] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg7") config.BtnOnMsg[7] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg7") config.BtnOffMsg[7] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel8") config.BtnLabel[8] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg8") config.BtnOnMsg[8] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg8") config.BtnOffMsg[8] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnLabel9") config.BtnLabel[9] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOnMsg9") config.BtnOnMsg[9] = urldecode(server.arg(i));
      if (server.argName(i) == "BtnOffMsg9") config.BtnOffMsg[9] = urldecode(server.arg(i));
      Serial.print(server.argName(i));
      Serial.print("=");
      Serial.println(server.arg(i));
    }
    WriteConfig();
    firstStart = true;
  }
  server.send_P ( 200, "text/html", PAGE_ButtonConfiguration ); 
  Serial.println(__FUNCTION__); 
}

