$(document).ready(function(){
    $(window).scroll(function(){
        // sticky navbar on scroll script
        if(this.scrollY > 20){
            $('.navbar').addClass("sticky");
        }else{
            $('.navbar').removeClass("sticky");
        }    
       
        // scroll-up button show/hide script
        if(this.scrollY > 500){
            $('.scroll-up-btn').addClass("show");
        }else{
            $('.scroll-up-btn').removeClass("show");
        }
    });

    // slide-up script
    $('.scroll-up-btn').click(function(){
        $('html').animate({scrollTop: 0});
        // removing smooth scroll on slide-up button click
        $('html').css("scrollBehavior", "auto");
    });

    $('.navbar .menu li a').click(function(){
        // applying again smooth scroll on menu items click
        $('html').css("scrollBehavior", "smooth");
    });

    // toggle menu/navbar script
    $('.menu-btn').click(function(){
        $('.navbar .menu').toggleClass("active");
        $('.menu-btn i').toggleClass("active");
    });

    // typing text animation script
    var typed = new Typed(".typing", {
        strings: ["Data Science", "AI", "Programming", "Psychology", "Social Science"],
        typeSpeed: 100,
        backSpeed: 60,
        loop: true
    });

    var typed = new Typed(".typing-2", {
        strings: ["Data Science", "AI", "Programming", "Psychology", "Social Science"],
        typeSpeed: 100,
        backSpeed: 60,
        loop: true
    });

    // drawing dynamic line percentage for each skil//
    $('.bars').each(function(){   
        //navigate to <div info> (child of bars) and call it info
        var info = $(this).children('.info');
        //1st span of div info which includes {Python, C, ...}
        var name = info.find('span:nth-child(1)').html().toLowerCase();
        //2nd span of div info which is the percentage
        var percent = info.find('span:nth-child(2)').html();
        selector = 'html';
        //selecting the line (2nd children) of the div bars
        var line = $(this).children('.line2');
        //var wdth = parseInt(percent) + '%';
        //add width = percentage to each <link "name">::before 
        $(this).append('<style>.'+ name +':before{width:' + percent + '!important;}</style>');
    });

    // owl carousel script 
    $('.carousel').owlCarousel({
        margin: 20,
        loop: true,
        autoplay: true,
        autoplayTimeOut: 2000,
        autoplayHoverPause: true,
        responsive: {
            0:{
                items: 1,
                nav: false
            },
            600:{
                items: 2,
                nav: false
            },
            1000:{
                items: 3,
                nav: false
            }
        }
    });

});

