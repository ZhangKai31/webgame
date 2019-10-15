var board1 = new Array();

$(document).ready(function() {
    init();
});

//初始化
function init() {
    for(var i = 0 ; i < 5; i ++)
        for(var j = 0 ; j <5; j ++){
            var gridCell = $("#cell1"+"-"+i+"-"+j);
            var gridCell1 = $("#cell2"+"-"+i+"-"+j);
            gridCell.css('top',getPosTop(i, j ));
            gridCell.css('left',getPosLeft(i, j ));
            gridCell1.css('top',getPosTop(i, j ));
            gridCell1.css('left',getPosLeft(i, j ));
        }
}

//开始游戏发牌
function startgame(){
    var oFso,oFile,sFile;
    sFile = "d:\\webgame\\game\\test.txt";

    oFso = new ActiveXObject("Scripting.FileSystemObject");

    var sign = new Array();
    for(var i=0;i<52;i++) sign[i]=0;

    for(var i = 0 ; i< 5; i ++){
        board1[i] = new Array();
        for(var j = 0; j < 5; j++){
            do {
                board1[i][j] = Math.floor(Math.random()*52)+1;
            }while (sign[board1[i][j]]==1)
            sign[board1[i][j]]=1;

        }
    }
    updateBoardView();

    oFile = oFso.OpenTextFile(sFile,2,true); //写方式打开
    for(var k=0;k<3;k++)
        for(var p=0;p<5;p++) {
            if (k == 0 && p == 3) break;
            oFile.Write(board1[k][p] + " ");
        }

    oFile.Close();
}

//更新牌
function updateBoardView() {

    for(var i = 0; i< 3; i++)
        for(var j = 0; j<5;j++){
            if(i==0&&j==3) break;
            $("#container1").append('<div class="puke" id="puke1-'+i+'-'+j+'"></div>');
            var thepuke1 = $('#puke1-'+i+'-'+j);
            thepuke1.css('top',getPosTop(i,j));
            thepuke1.css('left',getPosLeft(i,j));
            var img1="../Image/puke/("+board1[i][j]+").jpg";
            thepuke1.css('background-image',"url('"+img1+"')");
        }
}

//结束游戏
function endgame() {
    var oFso,oFile,sFile,sContent;
    sFile = "d:\\webgame\\game\\test.txt";

    oFso = new ActiveXObject("Scripting.FileSystemObject");

    oFile = oFso.OpenTextFile(sFile,1);  //只读方式打开
    sContent = oFile.ReadLine();
    var rec = new Array();
    rec=sContent.split(" ");
    oFile.Close();

    var n=0;
    for(var i=0;i<3;i++)
        for(var j=0;j<5;j++){
            if(i==0&&j==3) break;
            board1[i][j]=rec[n];
            n++;
        }


    updateBoardView();
}
























