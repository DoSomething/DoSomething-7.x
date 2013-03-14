  DoSomething webfonts: Use bit value to create combined css files to load certain webfont combinations.
  
  * The supported webfonts and the bit values are:
  
   Bit value: 1
   @font-face
     font-family: "din-web";
     src: url('DINWeb-CondMedium.eot');
     src: url('DINWeb-CondMedium.eot?iefix') format('eot'), url('DINWeb-CondMedium.woff') format('woff');
     font-style: normal;
     font-weight: 500;

   Bit value: 2
   @font-face
     font-family: "din-web"; 
     src: url('DINWeb-Cond.eot');
     src: url('DINWeb-Cond.eot?iefix') format('eot'), url('DINWeb-Cond.woff') format('woff');
     font-style: normal;
     font-weight: false;
  
   Bit value: 4
   @font-face
     font-family: "din-web";
     src: url('DINWeb-CondLight.eot');
     src: url('DINWeb-CondLight.eot?iefix') format('eot'), url('DINWeb-CondLight.woff') format('woff');
     font-style: normal;
     font-weight: 200;
  
   Bit value: 8
   @font-face
     font-family: "din-web";
     src: url('DINWeb-CondBlack.eot');
     src: url('DINWeb-CondBlack.eot?iefix') format('eot'), url('DINWeb-CondBlack.woff') format('woff');
     font-style: normal;
     font-weight: 700;
  
   Bit value: 16
   @font-face
     font-family: "din-web";
     src: url('DINWeb-CondBold.eot');
     src: url('DINWeb-CondBold.eot?iefix') format('eot'), url('DINWeb-CondBold.woff') format('woff');
     font-style: normal;
     font-weight: 600;
  
   Bit value: 32
   @font-face
     font-family: "din-web-reg";
     src: url('DINWeb.eot');
     src: url('DINWeb.eot?iefix') format('eot'), url('DINWeb.woff') format('woff');
     font-style: normal;
     font-weight: false;
     
   Bit value: 64
   @font-face {
     font-family: "din-web-reg";
     src: url('DINWeb-Medium.eot');
     src: url('DINWeb-Medium.eot?iefix') format('eot'), url('DINWeb-Medium.woff') format('woff');
     font-style: normal;
     font-weight: 500;
  
   Bit value: 128
   @font-face
     font-family: "din-web-reg";
     src: url('DINWeb-Light.eot');
     src: url('DINWeb-Light.eot?iefix') format('eot'), url('DINWeb-Light.woff') format('woff');
     font-style: normal;
     font-weight: 200;
  
   Bit value: 256
   @font-face {
     font-family: "din-web-reg";
     src: url('DINWeb-Bold.eot');
     src: url('DINWeb-Bold.eot?iefix') format('eot'), url('DINWeb-Bold.woff') format('woff');
     font-style: normal;
     font-weight: 600;