<?php

/**
 * Intended to be plugged in at the end of a pregnancy text drip message as an
 * mData. Will respond to any user message that matches a given set.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_preg_text_responder';
$workflow->title = 'Pregnancy Text Out-of-Flow Responder';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('out_of_flow_responder');

$activity = $workflow->newActivity('out_of_flow_responder');
$activity->name = 'out_of_flow_responder';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->response_sets = array(
  array(
    'phrase_match' => array('I hate you', 'suck it', 'kill yourself', 'die', 'youre the worst', 'shut up'),
    'word_match' => array('die'),
    'response' => array("That's no way to talk to a baby.", "Well that's not very nice", "Hey, be nice!"),
  ),
  array(
    'phrase_match' => array('Im not up', 'Im not awake'),
    'response' => array("You are now!"),
  ),
  array(
    'phrase_match' => array('I will feed you'),
    'response' => array("Thanks!"),
  ),
  array(
    'phrase_match' => array('Im tired'),
    'response' => array("Me too, being this cute is exhausting"),
  ),
  array(
    'phrase_match' => array('I dont want to bring you breakfast', 'I dont want to bring you breakfast in bed'),
    'response' => array("But I'm hungry!"),
  ),
  array(
    'phrase_match' => array('Feeds baby', 'heres breakfast', 'Im making breakfast'),
    'word_match' => array('Eggs', 'pancakes', 'waffles', 'bagles', 'milk', 'cereal', 'applesauce', 'bottle', 'feed'),
    'response' => array("Yum! I'll totally get you when I learn how to walk", "Nom nom nom"),
  ),
  array(
    'AND_match' => array(array('orange', 'juice')),
    'response' => array("Yum! I'll totally get you when I learn how to walk", "Nom nom nom"),
  ),
  array(
    'phrase_match' => array('good morning'),
    'word_match' => array('Goodmorning', ' morning'),
    'response' => array("Goodmorning!", "It IS a good morning!"),
  ),
  array(
    'phrase_match' => array('Youre cute', 'youre adorable'),
    'response' => array("I get my good looks from my parents", "Daww you're making me blush", "You sure know how to make a baby feel good", "Remember you said that next time I poop :)"),
  ),
  array(
    'phrase_match' => array('You get me breakfast'),
    'response' => array("I can't even stand up on my own yet!"),
  ),
  array(
    'phrase_match' => array('I dont want to', 'no'),
    'response' => array("But I'm the baby, you have to!"),
  ),
  array(
    'word_match' => array('Gross', 'ew', 'disgusting', 'fowl', 'smelly', 'stinky'),
    'response' => array("But my cute face balances it out..."),
  ),
  array(
    'phrase_match' => array('Its okay', 'thats okay'),
    'response' => array("Thanks for understanding"),
  ),
  array(
    'phrase_match' => array('Ill change my shirt', 'clean shirt'),
    'response' => array("That wasn't my favorite color on you anyway, it does nothing for your eyes"),
  ),
  array(
    'phrase_match' => array('fuck you', 'you suck', 'screw you', 'you bitch', 'blow job', 'butt plug', 'camel toe', 'dumb ass', 'hard on', 'jerk off', 'jungle bunny', 'pissed off', 'porch monkey', 'nut sack', 'sand nigger'),
    'word_match' => array('anus', 'arse', 'arsehole', 'ass', 'asshat', 'assjabber', 'asspirate', 'assbag', 'assbandit', 'assbanger', 'assbite', 'assclown', 'asscock', 'asscracker', 'asses', 'assface', 'assfuck', 'assfucker', 'assgoblin', 'asshat', 'asshead', 'asshole', 'asshopper', 'assjacker', 'asslick', 'asslicker', 'assmonkey', 'assmunch', 'assmuncher', 'asspirate', 'assshit', 'assshole', 'asssucker', 'asswad', 'asswipe', 'axwound', 'bastard', 'beaner', 'bitch', 'bitchass', 'bitches', 'bitchtits', 'bitchy', 'blowjob', 'bollocks', 'bollox', 'boner', 'brotherfucker', 'bullshit', 'bumblefuck', 'buttpirate', 'buttfucka', 'buttfucker', 'carpetmuncher', 'chesticle', 'chinc', 'chink', 'choad', 'chode', 'clit', 'clitface', 'clitfuck', 'clusterfuck', 'cock', 'cockass', 'cockbite', 'cockburger', 'cockface', 'cockfucker', 'cockhead', 'cockjockey', 'cockknoker', 'cockmaster', 'cockmongler', 'cockmongruel', 'cockmonkey', 'cockmuncher', 'cocknose', 'cocknugget', 'cockshit', 'cocksmith', 'cocksmoke', 'cocksmoker', 'cocksniffer', 'cocksucker', 'cockwaffle', 'coochie', 'coochy', 'coon', 'cooter', 'cum', 'cumbubble', 'cumdumpster', 'cumguzzler', 'cumjockey', 'cumslut', 'cumtart', 'cunnie', 'cunnilingus', 'cunt', 'cuntass', 'cuntface', 'cunthole', 'cuntlicker', 'cuntrag', 'cuntslut', 'dago', 'damn', 'deggo', 'dick', 'dicksneeze', 'dickbag', 'dickbeaters', 'dickface', 'dickfuck', 'dickfucker', 'dickhead', 'dickhole', 'dickjuice', 'dickmilk', 'dickmonger', 'dicks', 'dickslap', 'dicksucker', 'dicksucking', 'dicktickler', 'dickwad', 'dickweasel', 'dickweed', 'dickwod', 'dike', 'dildo', 'dipshit', 'doochbag', 'dookie', 'douche', 'douchefag', 'douchebag', 'douchewaffle', 'dumass', 'dumbass', 'dumbfuck', 'dumbshit', 'dumshit', 'dyke', 'fag', 'fagbag', 'fagfucker', 'faggit', 'faggot', 'faggotcock', 'fagtard', 'fatass', 'fellatio', 'feltch', 'flamer', 'fuck', 'fuckass', 'fuckbag', 'fuckboy', 'fuckbrain', 'fuckbutt', 'fuckbutter', 'fucked', 'fucker', 'fuckersucker', 'fuckface', 'fuckhead', 'fuckhole', 'fuckin', 'fucking', 'fucknut', 'fucknutt', 'fuckoff', 'fucks', 'fuckstick', 'fucktard', 'fucktart', 'fuckup', 'fuckwad', 'fuckwit', 'fuckwitt', 'fudgepacker', 'gay', 'gayass', 'gaybob', 'gaydo', 'gayfuck', 'gayfuckist', 'gaylord', 'gaytard', 'gaywad', 'goddamn', 'goddamnit', 'gooch', 'gook', 'gringo', 'guido', 'handjob', 'heeb', 'hell', 'ho', 'hoe', 'homo', 'homodumbshit', 'honkey', 'humping', 'jackass', 'jagoff', 'jap', 'jerkass', 'jigaboo', 'jizz', 'junglebunny', 'kike', 'kooch', 'kootch', 'kraut', 'kunt', 'kyke', 'lameass', 'lardass', 'lesbian', 'lesbo', 'lezzie', 'mcfagget', 'mick', 'minge', 'mothafucka', 'mothafuckin', 'motherfucker', 'motherfucking', 'muff', 'muffdiver', 'munging', 'negro', 'nigaboo', 'nigga', 'nigger', 'niggers', 'niglet', 'nutsack', 'paki', 'panooch', 'pecker', 'peckerhead', 'penis', 'penisbanger', 'penisfucker', 'penispuffer', 'piss', 'pissed', 'pissflaps', 'polesmoker', 'pollock', 'poon', 'poonani', 'poonany', 'poontang', 'porchmonkey', 'prick', 'punanny', 'punta', 'pussies', 'pussy', 'pussylicking', 'puto', 'queef', 'queer', 'queerbait', 'queerhole', 'renob', 'rimjob', 'ruski', 'sandnigger', 'schlong', 'scrote', 'shit', 'shitass', 'shitbag', 'shitbagger', 'shitbrains', 'shitbreath', 'shitcanned', 'shitcunt', 'shitdick', 'shitface', 'shitfaced', 'shithead', 'shithole', 'shithouse', 'shitspitter', 'shitstain', 'shitter', 'shittiest', 'shitting', 'shitty', 'shiz', 'shiznit', 'skank', 'skeet', 'skullfuck', 'slut', 'slutbag', 'smeg', 'snatch', 'spic', 'spick', 'splooge', 'spook', 'suckass', 'tard', 'testicle', 'thundercunt', 'tit', 'titfuck', 'tits', 'tittyfuck', 'twat', 'twatlips', 'twats', 'twatwaffle', 'unclefucker', 'vajj', 'vag', 'vagina', 'vajayjay', 'vjayjay', 'wank', 'wankjob', 'wetback', 'whore', 'whorebag', 'whoreface', 'wop'),
    'response' => array("You kiss your mother with that mouth?", "Woah, that's too much for my baby ears to handle"),
  ),
  array(
    'phrase_match' => array('Calm down'),
    'response' => array("I'm trying, I swear!"),
  ),
  array(
    'phrase_match' => array('Potty trained', ' potty train', ' use the toilet'),
    'response' => array("I won't be potty trained for at least another year, buckle up!"),
  ),
  array(
    'phrase_match' => array('Shake baby'),
    'response' => array("OW", "I'm not a doll! That hurts!"),
  ),
  array(
    'phrase_match' => array('Changed your diaper', 'youre all clean', 'Ill change you', 'changing you', 'clean now', 'diaper changed', 'change you', 'smelling good', 'changes diaper'),
    'word_match' => array('change', 'wash', 'clean'),
    'response' => array("So fresh and so clean clean", "Thanks!", "Thanks! When you smell better, you feel better"),
  ),
  array(
    'phrase_match' => array('change yourself'),
    'response' => array("I can't hold onto anything bigger than a pinky, how do you expect me to change my own diaper?", "Give me about 2 years and I totally will"),
  ),
  array(
    'phrase_match' => array('all done', 'I did it', 'I will', 'I am', 'I did', 'Im done', 'ok', 'okay', 'done'),
    'response' => array("You're the best!", "Thanks!", "Thank you!", "Phew, so much better"),
  ),
  array(
    'phrase_match' => array('I cant right now', 'not now', 'Ill do it later'),
    'response' => array("Mkay, I'll be here waiting.", "Just don't forget about me!"),
  ),
  array(
    'phrase_match' => array('I already changed you'),
    'AND_match' => array(array('change', 'already')),
    'response' => array("Well, I poop a lot.", "Call me Sir Poops A Lot"),
  ),
  array(
    'phrase_match' => array('Are you hungry', 'Do you need food', 'Do you need a bottle', 'Something to eat'),
    'response' => array("Yes please, I'm always hungry", "I could always eat", "A little snack sounds good"),
  ),
  array(
    'phrase_match' => array('Do you need to be changed', 'Diaper change', 'Check diaper', ' change diaper'),
    'response' => array("I pretty much always need my diaper changed", "Yeah, I think there might be a situation down town"),
  ),
  array(
    'phrase_match' => array('Are you sleepy', 'Are you tired'),
    'response' => array("I'm a little sleepy"),
  ),
  array(
    'phrase_match' => array('Please dont cry'),
    'response' => array("I'm a baby, it's what I do!"),
  ),
  array(
    'phrase_match' => array('Chill out'),
    'response' => array("This is me chilled out"),
  ),
  array(
    'phrase_match' => array('Stay still'),
    'response' => array("BUT I. DONT. WANNAAAAAA"),
  ),
  array(
    'phrase_match' => array('Im coming', 'Im here', 'here I come', 'coming', 'here'),
    'response' => array("Can't wait to see you!"),
  ),
  array(
    'phrase_match' => array('Youre ugly'),
    'response' => array("Well they tell me I look like my parents..."),
  ),
  array(
    'phrase_match' => array('Goo goo gaga'),
    'word_match' => array('tickle'),
    'response' => array("Aw, look at you trying to talk back. That's so cute."),
  ),
  array(
    'phrase_match' => array('Im at work', 'Im at school'),
    'response' => array("Okay, I'll try to be quiet til you're done"),
  ),
  array(
    'phrase_match' => array('get adopted', 'putting you up for adoption'),
    'response' => array("You don't mean that :("),
  ),
  array(
    'phrase_match' => array('snack time'),
    'response' => array("Nom nom nom nom"),
  ),
  array(
    'phrase_match' => array('I dont have to study'),
    'response' => array("Perfect! Then we can play alll night"),
  ),
  array(
    'phrase_match' => array('I dont take algebra', 'I already took algebra'),
    'response' => array("I can't even say my name yet, I don't know the difference between school subjects"),
  ),
  array(
    'phrase_match' => array('I dont want to sing'),
    'response' => array("But it'll make me shut up and go to sleep"),
  ),
  array(
    'phrase_match' => array('You do it'),
    'response' => array("I can't even say my own name yet, how am I supposed to do it?"),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;