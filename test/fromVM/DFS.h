#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
#include "opencv/cv.h"
#include "opencv/highgui.h"
class DFS {
private: 
	std::vector<std::vector<cv::Point>> vps;
	bool **marked;
	void dfs(const IplImage * img, cv::Point p, std::vector<cv::Point> &vp) {
		int x = p.x;
		int y = p.y;
		marked[x][y] = true;
		/*����ǰ�����vector��*/
		vp.push_back(p);
		/*�ж������ڵ�ֵ*/
		for(int a = x - 1; a <= x + 1; a++) {
			unsigned char * srow = (unsigned char *)(img->imageData + a * img->widthStep);
			for(int b = y - 1; b <= y + 1; b++) {

				if((x != a && y != b) && (srow[b])!= 0 && !marked[a][b]) {
					cv::Point p = cv::Point(a, b);
					dfs(img, p, vp);
				}
			}
		}
	}
public:
	/*�ݹ����ٶ�̫����*/
	DFS(const IplImage *img) {
		/*��ʼ��marked����*/
		marked = new bool*[img->height];
		for(int i = 0; i < img->height; i++)
			marked[i] = new bool[img->width];
		for(int i = 0; i < img->height; i++)
			for(int j = 0; j < img->width; j++)
				marked[i][j] = false;

		for(int i = 2; i < img->height - 2; i++) {
			for(int j = 2; j < img->width - 2; j++) {
				/*ÿ�ζ��½�һ��vp�����������ͬ������*/
				if(!marked[i][j]) {
					cv::Point p = cv::Point(i, j);
					std::vector<cv::Point> vp;
					dfs(img, p, vp);
					if(vp.size() > 5)
						vps.push_back(vp);
				}
			}
		}
	}
	std::vector<std::vector<cv::Point>> getPoints() {
				return vps;
	}
};