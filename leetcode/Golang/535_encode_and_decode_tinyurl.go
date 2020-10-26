/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 14:10:57
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 14:11:03
 */

type Codec struct {
	url map[string]string
}

func Constructor() Codec {
	return Codec{
		url: make(map[string]string),
	}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	temp := fmt.Sprintf("%x", longUrl)
	str := string([]byte(temp)[:10])
	this.url[str] = longUrl
	return str
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	return this.url[shortUrl]
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */
