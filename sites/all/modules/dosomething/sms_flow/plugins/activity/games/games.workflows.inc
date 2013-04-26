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
$activity->no_match_responses = array(
  "Aw, look at you trying to talk back. That's so cute. Goo-goo ga-ga.",
  "BbbbEEEEELLchh......hiccup.. hehehe. You were saying something?",
  "Shhhhhhh. No talking! Baby is sleeping.",
  "Shh don't get between a baby and it's food. I'm eating.",
  "I'm just a baby, I can't understand what you're saying.",
);
$activity->response_sets = array(
  array(
    'phrase_match' => array('I hate you', 'suck it', 'kill yourself', 'youre the worst', 'shut up'),
    'word_match' => array('die'),
    'response' => array("That's no way to talk to a baby. If you really really want me to go away, text AWAY and I'll be gone."),
  ),
  array(
    'phrase_match' => array('Who is this', 'Who are you', 'Who the hell is this', 'What is this'),
    'response' => array("I'm a phone baby your friend sent from DoSomething.org. I'll only text you today, but if you want me to go away, text AWAY."),
  ),
  array(
    'phrase_match' => array('Im not up', 'Im not awake'),
    'response' => array("You are now!"),
  ),
  array(
    'phrase_match' => array('I will feed you'),
    'AND_match' => array(array('feed', 'you')),
    'response' => array("Thanks!", "Thank you!", "You're the best."),
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
    'response' => array("Good morning!", "It IS a good morning!"),
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
    'exact_match' => array('no'),
    'phrase_match' => array('I dont want to'),
    'response' => array("But I'm the baby, you have to!"),
  ),
  array(
    'word_match' => array('Gross', 'ew', 'disgusting', 'fowl', 'smelly', 'stinky'),
    'response' => array("But my cute face balances it out..."),
  ),
  array(
    'word_match' => array('eww', 'ewww', 'ewwww', 'ewwwww'),
    'response' => array("It’s a good thing I’m so cute...it makes up for all of the smelly and gross."),
  ),
  array(
    'exact_match' => array('poop', 'fart'),
    'phrase_match' => array('its poop', 'its a poop', 'its a fart'),
    'response' => array("There’s no real right answer. You sort of lose either way."),
  ),
  array(
    'phrase_match' => array('Its okay', 'thats okay'),
    'response' => array("Thanks for understanding", "You're so understanding"),
  ),
  array(
    'phrase_match' => array('Ill change my shirt', 'clean shirt'),
    'response' => array("That wasn't my favorite color on you anyway, it does nothing for your eyes"),
  ),
  array(
    'phrase_match' => array('you ruined my shirt'),
    'response' => array("I’m sorry, sometimes these things just happen."),
  ),
  array(
    'phrase_match' => array('fuck you', 'you suck', 'screw you', 'you bitch', 'blow job', 'butt plug', 'camel toe', 'dumb ass', 'hard on', 'jerk off', 'jungle bunny', 'pissed off', 'porch monkey', 'nut sack', 'sand nigger'),
    'word_match' => array('anus', 'arse', 'arsehole', 'ass', 'asshat', 'assjabber', 'asspirate', 'assbag', 'assbandit', 'assbanger', 'assbite', 'assclown', 'asscock', 'asscracker', 'asses', 'assface', 'assfuck', 'assfucker', 'assgoblin', 'asshat', 'asshead', 'asshole', 'asshopper', 'assjacker', 'asslick', 'asslicker', 'assmonkey', 'assmunch', 'assmuncher', 'asspirate', 'assshit', 'assshole', 'asssucker', 'asswad', 'asswipe', 'axwound', 'bastard', 'beaner', 'bitch', 'bitchass', 'bitches', 'bitchtits', 'bitchy', 'blowjob', 'bollocks', 'bollox', 'boner', 'brotherfucker', 'bullshit', 'bumblefuck', 'buttpirate', 'buttfucka', 'buttfucker', 'carpetmuncher', 'chesticle', 'chinc', 'chink', 'choad', 'chode', 'clit', 'clitface', 'clitfuck', 'clusterfuck', 'cock', 'cockass', 'cockbite', 'cockburger', 'cockface', 'cockfucker', 'cockhead', 'cockjockey', 'cockknoker', 'cockmaster', 'cockmongler', 'cockmongruel', 'cockmonkey', 'cockmuncher', 'cocknose', 'cocknugget', 'cockshit', 'cocksmith', 'cocksmoke', 'cocksmoker', 'cocksniffer', 'cocksucker', 'cockwaffle', 'coochie', 'coochy', 'coon', 'cooter', 'cum', 'cumbubble', 'cumdumpster', 'cumguzzler', 'cumjockey', 'cumslut', 'cumtart', 'cunnie', 'cunnilingus', 'cunt', 'cuntass', 'cuntface', 'cunthole', 'cuntlicker', 'cuntrag', 'cuntslut', 'dago', 'damn', 'deggo', 'dick', 'dicksneeze', 'dickbag', 'dickbeaters', 'dickface', 'dickfuck', 'dickfucker', 'dickhead', 'dickhole', 'dickjuice', 'dickmilk', 'dickmonger', 'dicks', 'dickslap', 'dicksucker', 'dicksucking', 'dicktickler', 'dickwad', 'dickweasel', 'dickweed', 'dickwod', 'dike', 'dildo', 'dipshit', 'doochbag', 'dookie', 'douche', 'douchefag', 'douchebag', 'douchewaffle', 'dumass', 'dumbass', 'dumbfuck', 'dumbshit', 'dumshit', 'dyke', 'fag', 'fagbag', 'fagfucker', 'faggit', 'faggot', 'faggotcock', 'fagtard', 'fatass', 'fellatio', 'feltch', 'flamer', 'fuck', 'fuckass', 'fuckbag', 'fuckboy', 'fuckbrain', 'fuckbutt', 'fuckbutter', 'fucked', 'fucker', 'fuckersucker', 'fuckface', 'fuckhead', 'fuckhole', 'fuckin', 'fucking', 'fucknut', 'fucknutt', 'fuckoff', 'fucks', 'fuckstick', 'fucktard', 'fucktart', 'fuckup', 'fuckwad', 'fuckwit', 'fuckwitt', 'fudgepacker', 'gay', 'gayass', 'gaybob', 'gaydo', 'gayfuck', 'gayfuckist', 'gaylord', 'gaytard', 'gaywad', 'goddamn', 'goddamnit', 'gooch', 'gook', 'gringo', 'guido', 'handjob', 'heeb', 'hell', 'ho', 'hoe', 'homo', 'homodumbshit', 'honkey', 'humping', 'jackass', 'jagoff', 'jap', 'jerkass', 'jigaboo', 'jizz', 'junglebunny', 'kike', 'kooch', 'kootch', 'kraut', 'kunt', 'kyke', 'lameass', 'lardass', 'lesbian', 'lesbo', 'lezzie', 'mcfagget', 'mick', 'minge', 'mothafucka', 'mothafuckin', 'motherfucker', 'motherfucking', 'muff', 'muffdiver', 'munging', 'negro', 'nigaboo', 'nigga', 'nigger', 'niggers', 'niglet', 'nutsack', 'paki', 'panooch', 'pecker', 'peckerhead', 'penis', 'penisbanger', 'penisfucker', 'penispuffer', 'piss', 'pissed', 'pissflaps', 'polesmoker', 'pollock', 'poon', 'poonani', 'poonany', 'poontang', 'porchmonkey', 'prick', 'punanny', 'punta', 'pussies', 'pussy', 'pussylicking', 'puto', 'queef', 'queer', 'queerbait', 'queerhole', 'renob', 'rimjob', 'ruski', 'sandnigger', 'schlong', 'scrote', 'shit', 'shitass', 'shitbag', 'shitbagger', 'shitbrains', 'shitbreath', 'shitcanned', 'shitcunt', 'shitdick', 'shitface', 'shitfaced', 'shithead', 'shithole', 'shithouse', 'shitspitter', 'shitstain', 'shitter', 'shittiest', 'shitting', 'shitty', 'shiz', 'shiznit', 'skank', 'skeet', 'skullfuck', 'slut', 'slutbag', 'smeg', 'snatch', 'spic', 'spick', 'splooge', 'spook', 'suckass', 'tard', 'testicle', 'thundercunt', 'tit', 'titfuck', 'tits', 'tittyfuck', 'twat', 'twatlips', 'twats', 'twatwaffle', 'unclefucker', 'vajj', 'vag', 'vagina', 'vajayjay', 'vjayjay', 'wank', 'wankjob', 'wetback', 'whore', 'whorebag', 'whoreface', 'wop'),
    'word_match_exact' => TRUE,
    'response' => array("That's no way to talk to a baby. If you want me to go away, I will, just text AWAY.", "You kiss your mother with that mouth? If you want me to go away, I will, just text AWAY.", "Woah, that's too much for my baby ears to handle. If you want me to go away, I will, just text AWAY."),
  ),
  array(
    'phrase_match' => array('Calm down'),
    'AND_match' => array(array('calm', 'down')),
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
    'exact_match' => array('change yourself'),
    'phrase_match' => array('change yourself'),
    'response' => array("I can't hold onto anything bigger than a pinky, how do you expect me to change my own diaper?", "Give me about 2 years and I totally will"),
  ),
  array(
    'phrase_match' => array('Changed your diaper', 'youre all clean', 'Ill change you', 'changing you', 'clean now', 'diaper changed', 'change you', 'smelling good', 'changes diaper'),
    'word_match' => array('change', 'wash', 'clean'),
    'response' => array("So fresh and so clean clean", "Thanks!", "Thanks! When you smell better, you feel better"),
  ),
  array(
    'phrase_match' => array('all done', 'I did it', 'I will', 'I am', 'I did', 'Im done', 'ok', 'okay', 'done'),
    'response' => array("You're the best!", "Thanks!", "Thank you!", "Phew, so much better"),
  ),
  array(
    'phrase_match' => array('youre the best'),
    'response' => array("No you’re the best."),
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
    'response' => array("I pretty much always need my diaper changed", "Yeah, I think there might be a situation downtown"),
  ),
  array(
    'phrase_match' => array('Are you sleepy', 'Are you tired', 'are you sleep', 'are you asleep'),
    'response' => array("I'm a little sleepy"),
  ),
  array(
    'phrase_match' => array('Please dont cry'),
    'AND_match' => array(array('dont', 'cry')),
    'response' => array("I'm a baby, it's what I do!"),
  ),
  array(
    'phrase_match' => array('Chill out'),
    'AND_match' => array(array('chill', 'out')),
    'response' => array("This is me chilled out"),
  ),
  array(
    'phrase_match' => array('Stay still'),
    'AND_match' => array(array('stay', 'still')),
    'response' => array("BUT I. DONT. WANNAAAAAA"),
  ),
  array(
    'phrase_match' => array('Im coming', 'Im here', 'here I come', 'coming', 'here', 'im home'),
    'response' => array("Can't wait to see you!", "YAY!"),
  ),
  array(
    'phrase_match' => array('Youre ugly'),
    'response' => array("Well they tell me I look like my parents..."),
  ),
  array(
    'phrase_match' => array('Goo goo gaga', 'goo goo ga ga'),
    'AND_match' => array(array('goo', 'ga'), array('goo', 'gaga')),
    'response' => array("Aw, look at you trying to talk in my language. That's so cute."),
  ),
  array(
    'phrase_match' => array('Im at work', 'Im at school'),
    'response' => array("Okay, I'll try to be quiet til you're done"),
  ),
  array(
    'phrase_match' => array('driving me crazy', 'drive me crazy'),
    'response' => array("But the cuteness makes up for it :)"),
  ),
  array(
    'phrase_match' => array('get adopted', 'putting you up for adoption'),
    'response' => array("You don't mean that. If you really want me to go away though, I will, just text AWAY :("),
  ),
  array(
    'phrase_match' => array('snack time'),
    'response' => array("Nom nom nom nom"),
  ),
  array(
    'phrase_match' => array('There was no school today', 'school is already out', 'school has been out', 'Its the weekend', 'Its Saturday', 'Its Sunday'),
    'response' => array("I'm just a baby, I don't even know what day of the week it is. "),
  ),
  array(
    'phrase_match' => array('Yes I have to study'),
  ),
  array(
    'phrase_match' => array('I dont have to study'),
    'response' => array("Perfect! Then we can play allll night"),
  ),
  array(
    'phrase_match' => array('I dont take algebra', 'I already took algebra'),
    'response' => array("I can't even say my name yet, I don't know the difference between school subjects"),
  ),
  array(
    'phrase_match' => array('I cant sing', 'I dont know any lullabies', 'I dont know a lullaby'),
    'response' => array("I'm sure whatever you sing will be perfect."),
  ),
  array(
    'phrase_match' => array('I dont want to sing'),
    'response' => array("But it'll make me go to sleep"),
  ),
  array(
    'phrase_match' => array('You do it'),
    'response' => array("I can't even say my own name yet, how am I supposed to do it?"),
  ),
  array(
    'phrase_match' => array('Whats your name?'),
    'response' => array("That's your job! Just don't go all celeb on me and name me Flamingo or something."),
  ),
  array(
    'phrase_match' => array('Dont go', 'Dont go away', 'Dont leave', 'No dont leave baby'),
    'response' => array("Ok fine I won’t go, I would miss you too much anyway."),
  ),
  array(
    'exact_match' => array('boo'),
    'phrase_match' => array('peek a boo'),
    'response' => array("Ah! You scared me."),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;
